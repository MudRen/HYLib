// /d/kunming/xiaoximen
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "С����" );
        set("long", @LONG
�����������������ţ��׳�С���ţ�����������ɫ�˳���������
���οͣ����������ģ�Ҳ����Щ������ʿ��
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"dxiaolu", 
                "east"  :__DIR__"jinmafang",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
