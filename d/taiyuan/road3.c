// /d/taiyuan/road3.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵���������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG
        );
set("outdoors", "taiyuan");
set("exits", ([
                "northeast":__DIR__"road2", 
                "west":__DIR__"dukou1", 
                
	]));
       setup();
	replace_program(ROOM);
}
