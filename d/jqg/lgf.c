//liangongfang.c ������
//edit by snow
inherit ROOM;
#include <ansi.h>
void create()
{
           set("short",YEL"������"NOR);
           set("long",@LONG
�����������������Ϸ��ż������ţ���������ȵ���������������������
�������ĸ����ϸ�����һֻ��¯������������һ�ɵ�����������
LONG
);          
           set("exits",([
               "north": __DIR__"lang2",
           ]));

           setup();
           replace_program(ROOM);
}
