// ��·2
// by steel 

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
	���������,���겻����ѩ������˼��,�Ѿ�û����·,ֻ�ǰ�ã
ã��һƬ,�������κ����޵ĺۼ�,ֻ�б����ں�Х�š�ǰ��һ���ƺ������
�����ܡ�    
LONG
	);
	

	set("exits", ([
		"northeast" : __DIR__"iceroad3",
		"south" : __DIR__"iceroad1",
	]));
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="northeast")
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
