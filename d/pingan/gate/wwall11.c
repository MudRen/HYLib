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
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wwall10",
  "south"  : __DIR__"swcorner", 
]));
        set("outdoors", "pingan");
	setup();
}
 
