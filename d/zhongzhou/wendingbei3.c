inherit ROOM;

void create()
{
        set("short", "�Ķ�����");
        set("long", @LONG
�������ݳ��Ķ����֣����Ľֵ����˲�������һ������
���Ķ���������ݵ�Ѳ�������㲻���ӿ첽�����������ֵط�
������ȥΪ�����һ�����ӣ��ſڵ���ֻʯʨ�ӳ������
�۾����ſڻ���һֻ��ģ�ԭ����������ݵ������š�
LONG);

	set("outdoors", "zhongzhou");
        set("exits", ([
                "east" : __DIR__"xunbu",
                "south" : __DIR__"wendingbei2",
                "west" : __DIR__"yamen",
                "north" : __DIR__"wendingbei4",
        ]));

        set("objects",([
	        __DIR__"npc/old1" : 1,
	        __DIR__"npc/old2" : 1,
        ]));

        set("coor/x", -230);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
