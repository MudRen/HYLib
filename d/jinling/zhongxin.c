//jinling  zhongxin��c
inherit ROOM;

void create()
{
        set("short", "���Ĺ㳡");
        set("long", @LONG
�����ǽ����е�������,�����Ž���ǵ���Ҫ�ֵ����Ŷ�������������ʷ��
�ǡ��ػ��������������������ò��ٷ������²�Զǧ������һ�Ρ�
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"beijie2",
           "south" : __DIR__"nanjie1",
           "west" : __DIR__"xijie1",
           "east" : __DIR__"dongjie1",



]));
set("objects",([
              "/d/hainan/npc/man1" : 2,
__DIR__"npc/protect2":1,
]));
 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
