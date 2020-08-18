#
# Example of Perl hash
#
my	%hero = (  # identifier preceded by % holds a group of values, keyed by string
		"�Ƴ�"=>"����",
		"���"=>"�ŷ�",
		"����"=>"����",
		"����"=>"��"
	);
foreach $style (keys %hero)
	{ print "  ($style,$hero{$style})"; }	print "\n";
$hero{"����"} = "����";
foreach $style (keys %hero)
	{ print "  ($style,$hero{$style})"; }	print "\n";
foreach $style (sort keys %hero)
	{ print "  ($style,$hero{$style})"; }	print "\n";
foreach $style (reverse sort keys %hero)
	{ print "  ($style,$hero{$style})"; }	print "\n";