inherit ROOM;

void create()
{
        set("short", "���е�");
        set("long", @LONG
���Ǽ�СС�ĵ��̣����е����˾�˵��һ���޲����еľ�
�գ�ֻҪ����Ҫ��������ʱ��Ǯ�޲���һЩ��û�����������
ͭ��֮��Ķ����������ڵ��ϣ�����ȥ�����ҡ�
LONG);
        set("objects", ([
  		__DIR__"npc/smith" : 1,
	]));
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"wendingnan2",
	]));

        set("coor/x", -220);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
