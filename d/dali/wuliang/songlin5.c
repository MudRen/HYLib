// Room: songlin5.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "������");
	set("long", @LONG
����ǰ��Ȼһ�ڣ������У�ֻ������ǰ�󣬵�����������ǵص������֡�
��ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ���������
��˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�һ�Ų���ȥ������β����������ƺ���
ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
	);
	set("exits", ([ 
	    "south" : __FILE__,
            "north" : __DIR__"songlin"+(1+random(6)),
            "east" : __DIR__"pubu",
            "west" : __DIR__"songlin"+(1+random(6)),
        ]));
        set("outdoors", "����");
	setup();
        replace_program(ROOM);
}
