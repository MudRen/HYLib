//jinling  dangpu
#include <room.h>
inherit HOCKSHOP;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǽ���ǵ�������,���ڲ����ۺ�,�����������䵱�κ���Ʒ��
��������������������˲�ʱ����Ҳ����һд���صı�����ۡ�
LONG
        );
        set("exits", ([/* sizeof() == 4 */
       "east" : __DIR__"beijie2",
]));
set("objects", ([
  __DIR__"npc/dangpu_boss" : 1,
      ]) );

        set("no_clean_up", 0);

        setup();
}
