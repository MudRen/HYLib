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
  "northwest" : __DIR__"sichou4",
  "southeast" : __DIR__"heimiao",
]));
        set("objects", ([
        __DIR__"npc/police1" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1010);
        set("coor/y",2010);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
