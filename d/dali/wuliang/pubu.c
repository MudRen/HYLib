// Room: pubu.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "�������ٲ�");
	set("long", @LONG
���ֱ���һ��˫���������������������߳��˴����֡�������ˮ����
�������¡¡�����糱ˮ����һ�㣬̧ͷһ����ֻ�����������������ӵ�����
һ�����ٲ��Ӹ�����ֱк������
LONG
	);
	set("exits", ([ 
	    "west" : __DIR__"songlin1", 
            "southeast" : __DIR__"shanya",
        ]));
        set("objects", ([
                __DIR__"npc/ge_guangpei" : 1,
                __DIR__"npc/gan_guanghao" : 1,
        ]));
        set("outdoors", "����");

	setup();
}

int valid_leave(object me,string dir)
{ 
     if( dir == "southeast"
      && (present("gan guanghao", environment(me))))
         return notify_fail("�ɹ�������Цһ�������ӣ������������ɡ�\n");
     if( dir == "southeast"
      && (present("ge guangpei", environment(me))))
         return notify_fail("����������Цһ�������ӣ������������ɡ�\n");
         return ::valid_leave(me, dir);
}
