//jinling  huaihe.c
inherit ROOM;

void create()
{
        set("short", "�ػ���");
        set("long", @LONG
������ʮ�ﴺ������ǧ�����ٺӿ����������ǽ���ǵķ����ش������
�������ҡ�Ȩ���඼�۾��ڻ�ˮ�����������ʤ�ż�����ʷ�ƹʡ�����
���£����������������ԣ�����������ɧ�����̴�����
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"huafang",
          "west" : __DIR__"dongjie1",


]));
     set("outdoors", "jinling");

        set("objects", 
        ([
              "/d/hainan/npc/man1" : 2,
        ]));

        setup();
        replace_program(ROOM);
}