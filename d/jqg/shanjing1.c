//shanjing1.c ɽ��
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",YEL"ɽ��"NOR);
        set("long",@LONG
ɽ��ֻ��һ�����������ߴ�ֻ��ɽ��Խ��Խ�ߣ�Ҳ��Խ����᫡��Ա߳�
�Ÿ��־�������ɽʯ�β�Ļ���֮�£�Խ���Ե���ɭ�ɲ������ң�����Խ�ߣ�
ɽ��Խ��������������˫�����ۡ�
LONG
);

        set("outdoors","�����"); 
	set("exits",([
           "northup": __DIR__"shanding",
	   "southdown": __DIR__"shanjing",
	]));
	setup();
	replace_program(ROOM);
}

