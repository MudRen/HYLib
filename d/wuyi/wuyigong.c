// Room: /d/wuyi/wuyigong.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "���Ĺ�");
	set("long", @LONG
���Ĺ������ڴ�������´��Ϊ����ɽ�Ż��������ǲʹ���ڴ���̳
�������ľ������챦��䣬���ͽ���侴����챦����Ϊ���ɹۣ���
����������꣬��ּ�������������������࣬��ģ��󣬸����ûʡ���
����ʥ���꣬�ִ��޹��������Ϊ���ӹۣ�Ϊ���ξŴ�����֮һ����
�䡢½�Ρ��������Ⱦ��ڴ��ι���ٻ����ܣ����ڴ����鸳ʫ��Ԫ̩��
����ĳ����깬�������ݼ̹�·�����ģ����С������깬�ڡ�ʫ��һ��
����Ƕ���������ƽ²��������������ȡ���ӡ��Ը���������ɽ��
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : "/d/yanping/shandao1",
		"south" : __DIR__"1qu",
		"west" : "/d/fuzhou/wuyishan7",	
		"north" : __DIR__"path2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
