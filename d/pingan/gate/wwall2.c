inherit ROOM;
void create()
{
        set("short", "����ǽ2");
        set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nwcorner",
  "south"  : __DIR__"wwall1", 
]));
        set("outdoors", "pingan");
	setup();
}
 
