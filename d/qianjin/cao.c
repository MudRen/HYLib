inherit ROOM;
void create()
{
        set("short", "���ϲ�");
        set("long", @LONG
���ϲݣ��̴���ͨ��
�޴���Ϊ���軺��Ũ�̿��������������������
��������ɫһ���¡�
���Ӳ��������أ�����Զ�����ഺ����ӽ�����졣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"lastbridge",
  "southeast" : __DIR__"hua",
]));
        set("objects", ([
        __DIR__"npc/cao" : 1,
                        ]) );

        set("coor/x",-130);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
