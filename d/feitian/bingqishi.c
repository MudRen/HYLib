#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
��������Ż��������������ˡ���ǰ����ǽ��д��һ����(zi)�������ܵ�ǽ��
����ķ���һЩľ���ڼ׵ȶ������������Ҫ��ϰҲ������������ȡ����Ҫ��
���������벻Ҫ����Ϊ��������һЩ��
LONG);

  set("objects", ([ /* sizeof() == 2 */
           __DIR__"obj/zhujian.c" : 2,
           __DIR__"obj/tengjia.c" : 2,
]));

  set("item_desc", ([ /* sizeof() == 1 */
  "zi" : "��������������˶������������ˣ����µ����м�",
]));

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"daochang",
]));

  setup();
  replace_program(ROOM);
}
