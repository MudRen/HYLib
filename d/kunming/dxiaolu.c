// /d/dali/xiaolu
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "��ʯ·" );
        set("long", @LONG
һ����ʯ�������ʯ�̳ɣ�ƽ̹������̧ͷ��һ����ǰ��ĳ���
�����ɼ���

LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"dxiaolu1", 
                "east"  :"/d/kunming/xiaoximen",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
