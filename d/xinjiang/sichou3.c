 inherit ROOM;
void create()
{
        set("short", "���ӹʳ�");
        set("long", @LONG
�˳�λ���Ŷ����ι��У�ϵ��������ʮ��������ʦǰ������
�ʳǣ��óǽ����Ա����ϸ�ʮ���ɵĻ���̨���ϣ������޳�ǽ��
���±������� ��������Ȼ��
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"sichou2",
  "eastdown" : __DIR__"tulufan",
]));
        set("objects", ([
        __DIR__"npc/bird" : 2,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1070);
        set("coor/y",2030);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
