// /d/taiyuan/road1.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵���������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡���������
���˽�֪��̫ԭ�ˡ�
LONG
        );
set("outdoors", "taiyuan");
set("exits", ([
                "east":__DIR__"ximen", 
                "west":__DIR__"road2", 
                
	]));
       setup();
	replace_program(ROOM);
}
