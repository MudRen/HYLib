// /d/kunming/dongmen
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "����" );
        set("long", @LONG
  �����������Ķ����ţ�����������ɫ�˳�������������
�ͣ����������ģ�Ҳ����Щ������ʿ�����߿��Կ����̼��ʡ�
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"bijifang", 
                "east"  :__DIR__"qingshilu2",
]));
        setup();
        replace_program(ROOM);
}
