// "suiye"/dadao2.c
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
                "north":__DIR__"dadao1",  
                "south":"/d/mayi/beimen",  	
                "northeast":__DIR__"caoyuan",  
                 "southwest":"/d/xingxiu/shamo3",    
	]));
 set("objects",(["/clone/npc/man":2,]));
       setup();
	replace_program(ROOM);
}
