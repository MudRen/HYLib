// /guanwai/pubu.c

inherit ROOM;

void create()
{
	set("short", "�����ٲ�");
	set("long", @LONG
���ˮ��������߸߷������䣬����֮��Զ�����ˮ��ֱ����ֹȣ�
����Ȼ������ڡ������ӳ��ǡ�ư������գ�ˮ����������Ĺȵף�����
�ɸߵķ��ˣ�������Ůɢ�������������£�����Ծ��譲�׳��֮��������
ʫ�ƣ����׺����������ģ���ˮ�����������������������ѩ����ͬ��ʹ�
�����������ʯ�ɲ׺���ֱ�ɳ���ʶ�ţ����ʶ��Ȫ����Ȥ�������������
�Ρ���
LONG );
	set("exits", ([
		"southeast"  : __DIR__"damen",
		"westdown"   : __DIR__"xiaotianchi",
	]));
	set("no_clean_up", 0);
	set_temp("wayao2",1);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
