inherit ROOM;
void create()
{
        set("short", "����ǽ4");
        set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nupgate",
  "east"  : __DIR__"nwall10", 
]));
        set("outdoors", "pingan");
	setup();
}

 int valid_leave(object me, string dir) 
{
        object badguy;
 	if ( random(10)>8 && dir == "west" )
{		badguy=new("d/pingan/feizi/feizei");
		badguy->move("d/pingan/gate/nwall11");
 	return notify_fail("��Ȼ�ӳ�������һ����Ӱ��\n");
}
	else 
	{ 
 	return ::valid_leave(me, dir);
	}
}

