// ��·
// by steel 

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
	���������,���겻����ѩ������˼��,�Ѿ�û����·,ֻ�ǰ�ã
ã��һƬ,�������κ����޵ĺۼ�,ֻ�б����ں�Х�š�    
LONG
	);
        set("no_clean_up",0);
        set("out_doors","feihu");
	set("exits", ([
		"north" : __DIR__"iceroad2",
		"south" : __DIR__"road4",
	]));
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="north")
        {
         if((int)me->query_skill("dodge",1)<=70)
          {
         me->add("jing",-50);
         me->add("qi",-50);
          }
          else{
          me->add("jing",-30);
          me->add("qi",-30);
        }
        }
     return 1;     
}   
