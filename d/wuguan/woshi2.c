inherit ROOM;

void create()
{
    set("short","��Ϣ��");
    set("long", @LONG
����������ڵ���Ϣ�ң������е��ɣ����Ǵ�ɨ�ķǳ��ɾ���һ��
���̿�ǽ���ţ������ĵ��߹�ȥ���Ҹ�����˯��������
LONG);
	set("exits", ([
	    "west" : __DIR__"woshi1",
	]));
        set("no_fight",1);
             set("no_get",1);
        set("no_get_from",1);
        set("sleep_room", 1);
	setup();
      //       replace_program(ROOM)
}
