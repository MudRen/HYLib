//�캮ɽ
// by steel 

inherit ROOM;

void create()
{
	set("short", "�캮ɽ��");
	set("long", @LONG
	·�ѵ���ͷ,�����ƺ�������������,ǰ����һ��ɽ,Ρ��ͦ��,��
�����վ�,����Ŀ���Ǳ�����,Ҫ������ƺ��ȵ��컹�ѡ�����Ǽ����ຮ
֮���������캮ɽ��    
LONG
	);
	
       set("exits", ([
		"northup" : __DIR__"hill1",
		"southwest" : __DIR__"iceroad3",
                "east": __DIR__"iceroad4",      
	]));
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="northup"||dir=="east")
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
