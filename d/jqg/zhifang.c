//zhifang.c ֥��
// By River 99/05/20
inherit ROOM;
#include <ansi.h>
void init();
void create()
{
          set("short",HIG"֥��"NOR);
	  set("long",@LONG
�����ŵ�һ��ŨŨ���������㣬�����֥����ֻ�����ڵ�����ֲ���滨��
�ݣ�������������һ֦��֥������ȥ����ͨ����֥��Щ��һ����һ��������Ů
���ػ�������
LONG
           );

	 set("exits",([
               "north": __DIR__"lang5",
         ]));

         set("objects",([
             __DIR__"npc/gslve":1,
         ]));    
         setup();
         replace_program(ROOM);
}
