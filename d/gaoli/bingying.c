
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�
�����еĶ������������е����š�����������Ϣ����ǽ��������˧����
����ɫ��Ѱ�������ܡ����������������ȫ�������Χ�˹��������ƿ�
����̫�
LONG);

	
	set("exits", ([
		"north" : __DIR__"bingyingdamen",
	]));
 setup();
	replace_program(ROOM);
}	
