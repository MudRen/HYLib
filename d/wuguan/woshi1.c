inherit ROOM;

void create()
{
    set("short","��Ϣ��");
    set("long", @LONG
����������ڵ���Ϣ�ң������е��ɣ����Ǵ�ɨ�ķǳ��ɾ���һ��
���̿�ǽ���ţ������ȥҲ��һ����Ϣ�ң����ϵ����˽�����Ϣ���Ѻ�
��ȥ�������ĵ��Ҹ�����˯��������
LONG);
	set("exits", ([
	    "east" : __DIR__"woshi2",
            "south" : __DIR__"lang6",
        ]));
        set("no_get_from",1);
        set("no_fight",1);
        set("sleep_room", 1);
        set("no_get", 1);
	setup();
//     replace_program(ROOM);
}
