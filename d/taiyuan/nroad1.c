// /d/taiyuan/nroad1.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "��ٵ�");
	set("long", @LONG
������һ����������Ĵ�ٵ��ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵���������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡���������
ȥ���ص�·���������̫ԭ�ˡ�
LONG
        );
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "northwest":__DIR__"nroad2", 
                "south":__DIR__"beimen", 
                
	]));
       setup();
	replace_program(ROOM);
}
