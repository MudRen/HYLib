// quyuanfenghe.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ժ���");
        set("long", @LONG
�߽�ͤԺ��ֻ���ٺ�һ��С鿡�������һ����(duilian)�� ���
�ۺ���ֻ���ɻ����������������Զ���塣������������ӽ���Ͼ�
���������У���ⲻ����ʱͬ��������Ҷ����̣�ӳ�պɻ������족��
LONG);
        set("exits", ([
            "out"    : __DIR__"quyuanbei",
        ]));
        set("item_desc", ([
            "duilian" :
"\n
        ��              ��
        ��              ��
        ��              С
        ��              ��
        ˮ              ��
        Ӱ              ��
        ��              ��\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        set("he_count", 2);

        setup();
//        replace_program(ROOM);
}
void init()
{
        add_action("do_pick", "pick");
        add_action("do_pick", "zhai");
}

int do_pick(string arg)
{
        object me = this_player();
        object ob = new(__DIR__"obj/heye");

        if ( !arg || arg == "") return 0;

        if ( arg == "he ye" || arg == "��Ҷ" ){
                if (query("he_count") < 1) {
                        tell_object(me, "��ժ����ժ�˼һ�����������Ժ��ɡ��ˣ�\n", me);
                        return 1;
                }
                message_vision("$N�Ӻ���ժ��һƬ��Ҷ����\n", me);
                ob->move(me);
                add("he_count", -1);
                return 1;
        }
        return 0;
}

