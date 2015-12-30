var app = angular.module('StudentApp', ['ngMaterial']);


var fields = [
	{
		name: 'First name',
		endpoint: 'firstname',
		isInt: false,
	},
	{
		name: 'Last name',
		endpoint: 'lastname',
		isInt: false,
	},
	{
		name: 'Test score',
		endpoint: 'score',
		isInt: true,
	},
	{
		name: 'Class',
		endpoint: 'class',
		isInt: false,
	},
	{
		name: 'DOB',
		endpoint: 'date_birth',
		isInt: true,
	},
];


var intComps = [
	{
		name: '=',
	},
	{
		name: '<',
	},
	{
		name: '>',
	},
];

var strComps = [
	{
		name: '=',
	},
];

app.controller('AppController', function($http) {
		var vm = this;
		vm.fields = fields;
		vm.results = [];
		vm.getComp = function(field) {
			if (!field) {
				return [];
			}
			if (field.isInt) {
				return intComps;
			}
			return strComps;
		};

		vm.submit = function() {
			var data =  vm.field.endpoint + '=' + vm.value;
			if (vm.comp.name != '=') {
				data += '&ineq=' + vm.comp.name;
			}
			$http({
				method: 'POST',
				url: '/' + vm.field.endpoint,
				data: data,
			}).then(function successCallback(response) {
				console.log('suc');
				console.log(response);		
				vm.results = response.data;
			}, function errorCallback(response) {
				console.log(response);	
			});
		};
});
