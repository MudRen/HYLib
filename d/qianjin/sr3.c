inherit ROOM;
void create()
{
        set("short", "�ײ�");
        set("long", @LONG
�ײ�������ʪ�������˱ǡ����ϲյĸ������������Ǻϡ�һյ�����ĵ������Ŵ�
���ҡ�ڶ�����֨֨�����ı���������壬�ƺ�����ˮ����������յױ��䣬�ƺ���
�Ըе���ˮ��������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sr1",
]));

        set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
