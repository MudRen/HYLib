inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long",@LONG
��Ѭ������ϰ�����ĵط������ܵ�ľ�˳�Ʒ���ΰڷ��ţ��������
����ϰ�Թѵ����õİɡ�
LONG
);
	set("outdoors", "feitian");
	set("exits", ([
		"southwest" : __DIR__"xiangfang",
                        "southeast" : __DIR__"huayuan",
	]));
	set("objects",([
		__DIR__"npc/muren" : 6,
	]));
	setup();
	replace_program(ROOM);
}