inherit ROOM;
void create()
{
        set("short", "�ϳ�ǽ4");
        set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"supgate",
  "west"  : __DIR__"swall10", 
]));
        set("outdoors", "pingan");
        set("coor/x",-30);
	set("coor/y",-60);
	set("coor/z",30);
	setup();
}
 int valid_leave(object me, string dir) 
{
        object badguy;
 	if ( random(10)>8 && dir == "east" )
{		badguy=new("d/pingan/feizi/feizei");
		badguy->move("d/pingan/gate/swall11");
 	return notify_fail("��Ȼ�ӳ�������һ����Ӱ��\n");
}
	else 
	{ 
 	return ::valid_leave(me, dir);
	}
}

