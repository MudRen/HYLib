// room: laozhai.c
// Jay 4/8/96
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_break(string arg);

void create()
{
    set("short", "������լ");
    set("long", @LONG
�����Ǹ����ھ�����ͷ�������ڸ����ľɾӡ����ڵļҾߺ������˵�
���ڵ��ϡ������һ�ǽ���һ��֩���������ﵽ���ǳ�������Ȼ���Ѿ���
��û����ס�ˡ�����ľ�ͷ��һ����(men)�����ѱ�̮����ש�ߵ�ס�ˡ�
LONG
    );

    set("exits", ([
        "south" : __DIR__"xijie",
    ]));

    set("item_desc", ([
  "men" : "�������ѱ���ס�޷�ͨ�У����������(break)����\n",
    ]) );
    setup();
}

