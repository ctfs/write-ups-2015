# nullcon HackIM 2015: Programming Question 3

**Category:** Programming
**Points:** 300
**Author:**
**Description:**
>Design GPS device:
>
>#Problem Statement
>Now, Iron Man is on Mann planet. He need to go to the city of Aldrich Killian to capture him. Mann planet is extremely large and Iron Man has to travel a great distance to reach the City. In order to make the travel reliable, Iron Man wishes to design a GPS device, offcoarse, current GPS devices won't work on Mann planet. Help Iron Man to design GPS.
>
>Mann Planet has following four satellites:
>A with 120.5 (degree Azimuth) and 79.57 (degree Elevation)
>B with 102.14 (degree Azimuth) and 65.84 (degree Elevation)
>C with 112.8 (degree Azimuth) and 76.42 (degree Elevation)
>D with 134.25 (degree Azimuth) and 82.38 (degree Elevation)
>
>Each satellite broadcast GPS packet at regular intervals containing the time when the signal was broadcasted in Unix epoch time format. Let us denote t(A) to be a time when satellite A sent its signal. Let us further assume all the satellites send signals always at the same time.
>
>The GPS device receive the signal at another time (in device clock). GPS device may not have its clock synced with satellit clock. However, you may assume that all the satellites clocks are in sync the Univeral clock. Let b denote the drift of the GPS device clock at some point of time.
>
>##Input
>Last known measurements
>t(A, 0) = 1420473358
>t(B, 0) = 1420473357
>t(C, 0) = 1420473350
>t(D, 0) = 1420473351
>
>r(A, 0) = 1420473358.119169
>r(B, 0) = 1420473357.1193693
>r(C, 0) = 1420473350.109696
>r(D, 0) = 1420473351.1183686
>
>Last known coordinates of Iron Man
>E(0) = 1711639.22240641
>N(0) = 5908759.74357952
>U(0) = 1679966.70406394
>
>Current Measurements:
>t(A, 1) = 1420476958
>t(B, 1) = 1420476957
>t(C, 1) = 1420476950
>t(D, 1) = 1420476951
>
>r(A, 1) = 1420476958.129169
>r(B, 1) = 1420476957.1343694
>r(C, 1) = 1420476950.1201959
>r(D, 1) = 1420476951.1333687
>
>Speed of Light:
>299792458 m/s
>Output:
>delta(E)
>delta(N)
>delta(U)
>delta(b)
>
>All measurements should have exactly 3 decimal places. For example, in python, "%.3f" % (delta(E)) is a good approximation for delta(E)
>
>Submit you flag as:
>
>str(delta(E)) || ':' || str(delta(N) || ':' || str(delta(U)) || ':' || str(delta(b))
>
>with no spaces and where || is the string concatnation operator
>
>	[Input File](input3.txt)

## Write-up

(TODO)

## Other write-ups and resources

* none yet
