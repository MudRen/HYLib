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
		"east" : __DIR__"iceroad5",
		"west" : __DIR__"hill",
	]));
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="east")
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
