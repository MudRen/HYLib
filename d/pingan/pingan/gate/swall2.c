inherit ROOM;
void create()
{
        set("short", "�ϳ�ǽ2");
        set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"secorner",
  "west"  : __DIR__"swall1", 
]));
        set("outdoors", "pingan");
	setup();
        replace_program(ROOM);
}
