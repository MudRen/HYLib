// Room: /d/sandboy/inreed 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "«έ����");
  set ("long", @LONG
���涼�����������«έ,����ɫ��«έ���Ͽ����˰�ɫ��«��,΢�紵
��,«���������.������һƬ����,�����ĺ�ˮ��û������.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"inreed",
]));
  set("outdoors", "/d/sandboy");
  setup();
}
