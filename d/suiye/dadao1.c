// "suiye"/dadao1.c
// Room in ��Ҷ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "���ԭ");
	set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ�
�治���ߣ�������ƥ�����������ǵĺ����⡣
LONG
        );
set("outdoors", "suiye");
set("exits", ([
                "north":__DIR__"nanchengmen",  
                 "south":__DIR__"dadao2",    
	]));
       setup();
       replace_program(ROOM);
}
