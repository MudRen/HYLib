inherit ROOM;
void create()
{
        set("short", "����ǽ3");
        set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wwall11",
  "north"  : __DIR__"wupgate", 
]));
        set("outdoors", "pingan");
 	setup();
}
 int valid_leave(object me, string dir) 
{
        object badguy;
 	if ( random(10)>6 && dir == "north" )
{		badguy=new("d/pingan/feizi/feizei");
		badguy->move("d/pingan/gate/wwall10");
 	return notify_fail("��Ȼ�ӳ�������һ����Ӱ��\n");
}
	else 
	{ 
 	return ::valid_leave(me, dir);
	}
}

