#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "����");
		  set("long",@long
�����ǿ���������򵥣�ֻ��һЩ���Ӻ����ӣ������ϰ���д��͵��Ĺ�����ʳ�á�
���ٽ�����ʿ��Զǧ��������������ȵ�����ЪϢƬ�̣��ָ�һ�¡�
long);
		 set("exits",([
       "west" : __DIR__"elang01",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
