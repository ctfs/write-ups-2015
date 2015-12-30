import re, sys
if len(sys.argv) != 3: sys.exit(3)
with open(sys.argv[1], 'r') as f:
	stream = f.read()
results = re.findall(r'Content-Range: bytes (\d+)-(\d+)/\d+', stream)
if len(results) < 1: sys.exit(1)
(begin, end) = results[0]
begin = int(begin)
end = int(end)
print begin, end, len(stream), len(stream)-end+begin
with open(sys.argv[2], 'r+b') as f:
	f.seek(begin)
	f.write(stream[len(stream)-end+begin-1:])
	f.close()
