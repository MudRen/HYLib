#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","˫��կ��");
  set("long",@LONG
�������Ͻ�ɽ����������۾ӵĵط�����ľ��ɵ�ɽկ������һ����խ��ɽ
�ڴ������߽���ɽʯ��կ�ſ�һ��������������½��Ե�ͼ����ӭ��Ʈ��ɶ�
��һ·��ɽ���ǽ���ǡ���������ɽկ���ɾ�......
LONG);
  set("exits",([
    "westdown"   : __DIR__"zijinshan2",
    "eastdown"  : __DIR__"zijinshan",
//    "north"  : __DIR__"juyiting",
  ]));
   set("objects",([
              "/d/hainan/npc/man4" : 1,
   ]));
  setup();
        replace_program(ROOM);
}
