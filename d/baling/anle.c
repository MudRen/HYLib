


inherit ROOM;


void create()
{
	set("short", "�ᶼ��");
	set("long", @LONG
   �ᶼ��λ���Ĵ���ض��ϱ�Ե���ش��������Σ�
�ᶼ��һ����ɽ��ˮ�Ĺųǣ�����ʱ�ơ����ӱ�
LONG);
	
	set("exits", ([
                "south" : __DIR__"eroad",
                "northeast" : __DIR__"tulu2",
                "southwest" : __DIR__"shandao8",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
