inherit ROOM;

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
�������ݳ�����ҩ�̡�����ͨҩ�ĵ�������в�ҩһӦ
��ȫ��ŨŨ��ҩζ�����е�͸�����������������������ģ���
�ĳ��˴����ⲻ��������Ҫҩ�Ļ�������С����һ�㣬����
��ҩ����Ժ�����������Լ���ҩ��
LONG);
        set("objects", ([
  		"/d/city/npc/huoji" : 1,
	]));

        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"yaopuboss",
  		"west" : __DIR__"wendingbei2",
  		"south" : __DIR__"yaopu1",
	]));

        set("coor/x", -220);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
