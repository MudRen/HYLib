 inherit ROOM;
void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
һ���������ܲ����۵���·��������ǧ�����ʷ�У�������ʳ��
�����˵������������ǵİ׹����ڵ�·���ԡ�������������ô�Ĳ���
�ۣ��ƺ�һ������ĺ��Ӷ����Խ�����ڽ��¡�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"tulu4",
  "southeast" : __DIR__"sichou2",
]));
/*
        set("objects", ([
        __DIR__"npc/yaren" : 1,
        __DIR__"npc/prince" : 1,
                        ]) );
*/
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1090);
        set("coor/y",2050);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
