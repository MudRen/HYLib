// Room: /d/japan/tiejiangpu
inherit ROOM;

void create()
{
  set ("short", "��������");
  set ("long", @LONG
ӭ����һ���ܴ�Ļ�¯.�и��һ���������,ϵ�Ŵֲ�Χȹ���ڴ���.
�Աߵ�һ��С����ʹ�����ŷ���.ǽ�Ϲ��ż��ѵ�,��ʲô��.�м�������
���ڵ�����,�������ⲻ��.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jiedaoe1",
]));
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/jiujing" : 1,
            ]));
  setup();
}
