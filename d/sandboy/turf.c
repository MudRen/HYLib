// Room: /d/sandboy/turf 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "��ݵ�");
  set ("long", @LONG
�峿�����İ�ɫ�������ڲݵ��Ͽ�����,����һƬ���˵��̻���������
��,�˴����Ƶ���,�򱱿�,һƬ�߸ߵ�é����ס�����,�����Ǹ߸ߵ͵�
��һƬ������,���и�С����.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"trees1",
  "north" : __DIR__"inturf",
  "east" : __DIR__"pond",
]));
set("outdoors","/d/jiangnan");
  setup();
}
