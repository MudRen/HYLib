//shufang.c �鷿
inherit ROOM;
#include <ansi.h>
void create()
{
          set("short",HIC"�鷿"NOR);
	  set("long",@LONG
������������ż�����ܣ������ǹ���ֹ���鷿����ߵ������������һ
Щ�����书���鼮���ұߵ������������һЩʫ�ʡ����׷���һ�����ӣ��߽�
һ�������Ϸ���һЩ�������д��ʫ�ʡ��鷿��ȥ�Ƕ��᳤�ȡ�
LONG
           );

	  set("exits",([
              "west": __DIR__"lang3",
          ]));
                  
          set("item_desc",([
               "jia":"�������ϰڷ��Ų����鼮��\n",
          ]));
	  setup();
          replace_program(ROOM);
}
