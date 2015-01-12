# HackIM CTF 2014: programming 200

**Category:** prorgramming
**Points:** 200
**Description:**

> Teleport Iron Man:
>
> Iron Man got the coordinates of Aldrich Killian. According to the coordinates, Aldrich Killian is hiding in a planet called Mann's planet in a distant galaxy. Iron Man found out a secret quantum communication channel from Earth to Mann's planet, generally used by Aldrich Killian. However, Iron Man is novice in Quantum Computing and Teleportation. Help Iron Man to teleport himself to the remote and hostile planet.
>
> Following is the short summary of how you can help Iron Man.
>
> Consider two parties named Alice and Bob (you). Alice wants to transmit a qubit to Bob security without revealing anything to Eve. Eve can intercept any classical communication channels. PS:You know who I am talking about, isn't it?
>
> Suppose, Alice wants to send a qubit |t> = a|0> + b|1> to Bob. For simplicity, a qubit can also be described as a pair/tuple (a, b).
>
> As the Quantum Communication Channel, Alice and Bob each possess one qubit of an entangled pair
>
> |s0> = (1/sqrt(2)) (|00> + |01>)
>
> So the start state is three-qubit quantum state:
>
> |t> * |s0> = (1/sqrt(2)) (a|0⟩*(|00⟩+|11⟩)+b|1⟩*(|00⟩+|11⟩))
> = (1/sqrt(2)) (a|000⟩+a|011⟩+b|100⟩+b|111⟩)
>
> (Please note * is the tensor product operator).
>
> As a result, Alice controls the first two qubits and Bob controls the last one.
> To transmit the qubit |t>, there are two steps involved:
>
> *Step 1:*
>
> Alice apply (Cnot * I) operator followed by (H * I * I) on the 3 qubit state (|t> * |s0>) i.e.
> (H * I * I)(Cnot * I)(|t⟩*|s0⟩)
>
> The result of this will be entangled 3 qubit state.
>
> *Step 2:*
>
> Alice measures the first two qubits and obtains one of the four standard basis states |00⟩, |01⟩, |10⟩, and |11⟩ with some probability. Depending on the result of her measurement, the quantum state of Bob’s qubit will be projected to certain ensemble of 1-qubit states. Alice sends the result of her measurement as two classical bits 00 or 01 or 10 or 11 to Bob.
>
> *Step 3*
>
> When Bob receives the two classical bits from Alice, he knows how the state of his half of the entangled pair compares to the original state of Alice’s qubit. Bob can reconstruct the original state of Alice’s qubit, |t⟩, by applying the appropriate decoding transformation (unitary operators) to his qubit, originally part of the entangled pair.
>
> So this is how Bob got a single qubit from Alice.
>
> * N Qubit Teleportation Problem *
>
> Alice wants to transmit n qubits to Bob. Let us say n qubits are
>
> |t1> = = a1|0> + b1|1> |t2> = = a2|0> + b2|1> ... |tn> = = an|0> + bn|1>
>
> Assume, Alice and Bob need to share n Entangled pairs |s1>, |s2> .. |sn> between each other.
>
> |s1> = (1/sqrt(2)) (|00> + |01>) |s2> = (1/sqrt(2)) (|00> + |01>) ... |sn> = (1/sqrt(2)) (|00> + |01>) 
>
>
> ## Input First line will specify n, number of qubits to transfer by Alice to Bob. Each of the next n lines contain 2 bits information, i.e. 00 or 01 or 10 or 11, sent from Alice to Bob via classical communication channel. Each of next n lines contain pair of integers separated by a space. Each pair of integers describe result of Bobs qubit once Alice perform measurement on here two qubits as part of Step 2.
>
> ## Output Capture the Flag. The Flag is the summary of qubits Bob has received from Alice.
> Summary(|t1>, |t2> ... |tn>) = [(a1 * 1 + b1) + (a2 * 2 + b2) + .. + (an * n + bn) ] % 1000000007 where as we described |ti> = ai|0> + bi|1> is final ith qubit Bob has received from Alice, * is classical multiply operator
>
> ## Example 
>
> ### Sample Input
> 2
> 00
> 00
> 1 2
> 4 8
> ### Sample Flag
> 19
> Bob has received following qubits from Alice
> (1 2)
> (4 8)
> So the flag is 19 = ((1*1 + 2) + (4*2 + 8) ) % 1000000007
>
>	[Input File](input.txt)

## Write-up

(TODO)

## Other write-ups and resources

* none yet
