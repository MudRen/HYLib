 inherit ROOM;
void create()
{
        set("short", "û�����ֵĵط�");
        set("long", @LONG
�����Ǹ�����ֵĵط����ڲ����ط�������ů�紺������ҹ��
����ط����ǹ������硣�����оƣ�ȴ���Ǿ�¥���жģ�ȴ���Ƕĳ���
����ʱ�����������κ��µ�Ů�ˣ�ȴҲ���Ǽ�Ժ����ط�����û����
�֣�ȴ�Ǹ����������������ĵط��������а���ʮ�������ӣ�������
ѡ����һ���������������㶼�������ܵ���õľƲˡ�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"beimen",
  "south" : __DIR__"bazha",
]));
        set("objects", ([
//        __DIR__"npc/hong" : 1,
        __DIR__"npc/hua" : 1,
                        ]) );
     
        
        set("coor/x",-1120);
        set("coor/y",2100);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
