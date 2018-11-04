// liandan2.c ������
// ����lywin 2000/6/15 

#include <ansi.h>
inherit ROOM;
int do_liandan(string arg);
int do_hc(string arg);
int do_put(string arg);


string *dan1 = ({"/clone/misc/jinchuang","/clone/misc/gaoyao","/clone/misc/dust"});
string *dan2 = ({"/clone/misc/yangjing","/clone/misc/xiaohuan-dan"});
string *dan3 = ({"/clone/misc/kongquedan","/clone/misc/hedinghong","/clone/misc/bicanfeng"});
string *dan4 = ({"/clone/misc/kongquedan","/clone/misc/hedinghong","/clone/misc/bicanfeng","/clone/misc/dahuan-dan","/clone/misc/zhujingchan","/clone/misc/wuchangdan",
"/clone/misc/jiuhua"});
string *dan5 = ({"/clone/misc/kongquedan","/clone/misc/hedinghong","/clone/misc/bicanfeng","/clone/misc/dahuan-dan","/clone/misc/zhujingchan","/clone/misc/wuchangdan",
"/clone/misc/jiuhua","/d/shenlong/obj/baihua","/d/city/npc/obj/shouwu","/d/quanzhen/npc/obj/gao"});
string *dan6 = ({"/clone/misc/kongquedan","/clone/misc/hedinghong","/clone/misc/bicanfeng","/clone/misc/dahuan-dan","/clone/misc/zhujingchan","/clone/misc/wuchangdan",
"/clone/misc/jiuhua","/d/shenlong/obj/baihua","/d/city/npc/obj/shouwu","/d/quanzhen/npc/obj/gao","/d/xiakedao/obj/zhou","/quest/feizei/lingzhi"
,"/quest/liandan/dan/ngdan1","/quest/liandan/dan/ngdan2","/quest/liandan/dan/ngdan3","/quest/liandan/dan/ngdan4","/quest/liandan/dan/ngdan5","/quest/liandan/dan/ngdan6","/quest/liandan/dan/ngdan7","/quest/liandan/dan/ngdan8","/quest/liandan/dan/ngdan9"});
string *dan7 = ({"/quest/liandan/dan/z-dan","/quest/liandan/dan/n-dan"});
string *dan8 = ({"/quest/liandan/dan/z-dan","/quest/liandan/dan/n-dan","/clone/misc/yangjing","/clone/misc/xiaohuan-dan","/clone/misc/jinchuang","/clone/misc/gaoyao","/clone/misc/dust","/quest/liandan/dan/bdan1","/quest/liandan/dan/bdan2","/quest/liandan/dan/bdan3","/quest/liandan/dan/bdan4","/quest/liandan/dan/bdan5"
,"/quest/liandan/dan/nbdan1","/quest/liandan/dan/nbdan2","/quest/liandan/dan/nbdan3"});
string *dan9 = ({"/quest/liandan/dan/z-dan","/quest/liandan/dan/n-dan","/clone/misc/yangjing","/clone/misc/xiaohuan-dan","/clone/misc/jinchuang","/clone/misc/gaoyao","/clone/misc/dust","/quest/liandan/dan/ndan1","/quest/liandan/dan/ndan2","/quest/liandan/dan/ndan3","/quest/liandan/dan/ndan4","/quest/liandan/dan/bdan1","/quest/liandan/dan/bdan2","/quest/liandan/dan/bdan3","/quest/liandan/dan/bdan4","/quest/liandan/dan/bdan5"
,"/quest/liandan/dan/nxdan1","/quest/liandan/dan/nxdan2","/quest/liandan/dan/nxdan3","/quest/liandan/dan/nxdan4","/quest/liandan/dan/nxdan5","/quest/liandan/dan/nxdan6","/quest/liandan/dan/nxdan7","/quest/liandan/dan/nxdan8","/quest/liandan/dan/nxdan9"});
string *dan10 = ({"/quest/liandan/dan/z-dan","/quest/liandan/dan/n-dan","/clone/misc/yangjing","/clone/misc/xiaohuan-dan","/clone/misc/jinchuang","/clone/misc/gaoyao","/clone/misc/dust","/quest/liandan/dan/ndan1","/quest/liandan/dan/ndan2","/quest/liandan/dan/ndan3","/quest/liandan/dan/ndan4","/quest/liandan/dan/bdan1","/quest/liandan/dan/bdan2","/quest/liandan/dan/bdan3","/quest/liandan/dan/bdan4","/quest/liandan/dan/bdan5","/quest/liandan/dan/gdan1","/quest/liandan/dan/gdan2","/quest/liandan/dan/gdan3","/quest/liandan/dan/gdan4","/quest/liandan/dan/gdan5"
,"/quest/liandan/dan/ngdan1","/quest/liandan/dan/ngdan2","/quest/liandan/dan/ngdan3","/quest/liandan/dan/ngdan4","/quest/liandan/dan/ngdan5","/quest/liandan/dan/ngdan6","/quest/liandan/dan/ngdan7","/quest/liandan/dan/ngdan8","/quest/liandan/dan/ngdan9"
,"/quest/liandan/dan/nxdan1","/quest/liandan/dan/nxdan2","/quest/liandan/dan/nxdan3","/quest/liandan/dan/ngdan4","/quest/liandan/dan/nxdan5","/quest/liandan/dan/nxdan6","/quest/liandan/dan/nxdan7","/quest/liandan/dan/nxdan8","/quest/liandan/dan/nxdan9"
});

 void create()
{
        set("short", "������");
        set("long", @LONG
����ƽһָƽʱ�����ĵط������Ѵ��Ĵ��ռ����Ĳ�ҩ�õ��������
�ɸ��ֵ�ҩ��һ�㶼ֻ������Щ��ƽ����ҩ��������ʱҲ��������������
��ҩ��������԰�һЩ�����Ĳ�ҩ�Ž�(putinto)  ҩ¯���кϳ�(hecheng) ��
LONG
        );

        set("exits", ([
                "east" : "/quest/liandan/liandan1",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

void init()
{
        add_action("do_put","putinto");
        add_action("do_hc","hecheng");
        add_action("do_liandan","liandan"); 
        add_action("do_quit","quit");
        add_action("do_quit","exit");
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
        add_action("do_quit","exert");
        add_action("do_quit","learn"); 
        add_action("do_quit","yun");
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna"); 
        add_action("do_quit","fight");
        add_action("do_quit","hit");
        add_action("do_quit","perform");
        add_action("do_quit","persuade");
        add_action("do_quit","quanjia");
        add_action("do_quit","practice");
        add_action("do_quit","lian"); 
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
}

int do_liandan(object ob)
{
        object me=this_player(); 
 
        if (!(ob = present("yao cao", this_player())))
                return notify_fail("������û��ҩ�ݣ�������ʲô����\n");
                 
        if ( (int)me->query("jing")<50)
                return notify_fail("��ľ������㣬�޷�������\n");

        if ( (int)me->query("qi")<50)
                return notify_fail("����岻�㣬�޷�������\n");

        if ( (int)me->query("neili")<100)
                return notify_fail("����������㣬�޷�������\n");
    
    	if( me->is_busy() )
		return notify_fail("������æ��!\n");
        
        if ( ob->query("lev") == 1 )
        {
        message_vision(HIY"$N����ͨҩ�ݷŽ�¯�У��������£������¯��ʼ������\n"NOR,me); 
        destruct(ob);
        me->add("jing",-30);
        me->add("qi",-30);
        me->add("neili",-50);
        me->start_busy(9); 
       	call_out("liandan1",6,me);
        return 1;
        }
        else
        if ( ob->query("lev") == 2 )
        {
        message_vision(HIR"$N�����ҩ�ݷŽ�¯�У��������£������¯��ʼ������\n"NOR,me); 
        destruct(ob);
        me->add("jing",-50);
        me->add("qi",-50);
        me->add("neili",-100);
        me->start_busy(11); 
       	call_out("liandan2",8,me);
        return 1;
        }
}

int liandan1(object me)
{
        object ob;
        if ((int)me->query_skill("liandan", 1) < 30 )
        {
           message_vision(HIY"ֻ��¯�л����ƺ����㣬$N��æ���ڹ�����¯������\n"NOR,me); 
           message_vision(HIY"��һ����鵤�ѳɡ�\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan1[random(3)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 150 )
        {
           message_vision(HIY"ֻ��¯�л����ƺ����㣬$N��æ���ڹ�����¯������\n"NOR,me); 
           message_vision(HIY"��һ����鵤�ѳɡ�\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan10[random(39)]);
           ob->move(me);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 120 )
        {
           message_vision(HIY"ֻ��¯�л����ƺ����㣬$N��æ���ڹ�����¯������\n"NOR,me); 
           message_vision(HIY"��һ����鵤�ѳɡ�\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan9[random(25)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 80 )
        {
           message_vision(HIY"ֻ��¯�л����ƺ����㣬$N��æ���ڹ�����¯������\n"NOR,me); 
           message_vision(HIY"��һ����鵤�ѳɡ�\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan8[random(15)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 59 )
        {
           message_vision(HIY"ֻ��¯�л����ƺ����㣬$N��æ���ڹ�����¯������\n"NOR,me); 
           message_vision(HIY"��һ����鵤�ѳɡ�\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan7[random(2)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 29 )
        {
           message_vision(HIY"$N���������в��پ��飬���Ų�æ�Ľ�����ע��¯�С�\n"NOR,me); 
           message_vision(HIY"��һ����鵤�ѳɡ�\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan2[random(2)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }       
} 

int liandan2(object me)
{
        object ob; 
        if ((int)me->query_skill("liandan", 1) < 30 )
        {
           message_vision(HIR"ֻ��¯�л����ƺ����㣬$N��æ���ڹ�����¯������\n"NOR,me); 
           message_vision(HIR"����ҩ������֮�����������ǲ��㣬$Nֻ����һ�α���������\n"NOR,me); 
           message_vision(HIR"���������鵤��$N��������һ������\n"NOR,me);
           me->add("combat_exp",50+random(30));
           me->add("potential",25+random(10));
           ob=new(dan3[random(3)]);
           ob->move(me);       
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));  
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 199 )
        {
           message_vision(HIW"$N��������֮�����������˺�һ��\n"NOR,me); 
           message_vision(HIW"��Ȼ��ҩ�ݷǳ�������$NҲ�������ţ��Ƚ��ؽ�����ע��¯�С�\n"NOR,me); 
           message_vision(HIW"$N����������һ�������������µ���ҩ��\n"NOR,me);
           me->add("combat_exp",50+random(30));
           me->add("potential",25+random(10));
           ob=new(dan6[random(21)]);
           ob->move(me);       
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));  
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 150 )
        {
           message_vision(HIY"ֻ��¯�л����ƺ����㣬$N��æ���ڹ�����¯������\n"NOR,me); 
           message_vision(HIY"��һ����鵤�ѳɡ�\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan10[random(39)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 100 )
        {
           message_vision(HIY"ֻ��¯�л����ƺ����㣬$N��æ���ڹ�����¯������\n"NOR,me); 
           message_vision(HIY"��һ����鵤�ѳɡ�\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan9[random(25)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else  
        if ((int)me->query_skill("liandan", 1) > 80 )
        {
           message_vision(HIW"$N��������֮�������Ƿǳ���ͨ��\n"NOR,me); 
           message_vision(HIW"��Ȼ��ҩ�ݷǳ�������$NҲ�������ţ��Ƚ��ؽ�����ע��¯�С�\n"NOR,me); 
           message_vision(HIW"��һ����ʹ󹦸�ɡ�\n"NOR,me);
           me->add("combat_exp",50+random(30));
           me->add("potential",25+random(10));
           ob=new(dan5[random(10)]);
           ob->move(me);       
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));  
           return 1;
        }
        else 
        if ((int)me->query_skill("liandan", 1) > 60 )
        {
           message_vision(HIR"$N��������֮���������ᳵ��·��\n"NOR,me); 
           message_vision(HIR"��Ȼ��ҩ�ݷǳ�������$NҲ�������ţ��Ƚ��ؽ�����ע��¯�С�\n"NOR,me); 
           message_vision(HIR"��һ����ʹ󹦸�ɡ�\n"NOR,me);
           me->add("combat_exp",50+random(30));
           me->add("potential",25+random(10));
           ob=new(dan4[random(7)]);
           ob->move(me);       
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));  
           return 1;
        }       
        else
        if ((int)me->query_skill("liandan", 1) > 30 )
        {
           message_vision(HIY"ֻ��¯�л����ƺ����㣬$N��æ���ڹ�����¯������\n"NOR,me); 
           message_vision(HIY"��һ����鵤�ѳɡ�\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan8[random(15)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
} 

int do_quit(string arg)
{
        write(this_player()->query("name")+"�����ĵ������ɣ�\n");
        return 1;
}


int do_put(string arg)
{
	mixed no_drop;
 object obj;object me;
 me=this_player();
	if(!arg) return notify_fail("��Ҫ��ʲô������ҩ¯�У�\n");
		if( !objectp(obj = present(arg, me)) )
			return notify_fail("������û������������\n");

	if( me->is_busy() )
		return notify_fail("������æ��!\n");

	
	if( obj->query_temp("is_rided_by") == me)
		return notify_fail( obj->name() + "�������������š�\n");
	if( !obj->query("yaocao") )
		return notify_fail( obj->name() + "�����������ܺϳɵ�ҩ��\n");

	if( userp(obj) )
		return notify_fail( obj->name() + "�����������ܺϳɵ�ҩ��\n");

    me->add_temp("liandanyc",1);
        message_vision("$N��"+obj->query("name")+"�Ž�¯�С�\n"NOR,me); 
        me->start_busy(2); 
   	destruct(obj);    
		return 1;
}


int do_hc(object ob)
{
        object me=this_player(); 
 
        if (!me->query_temp("liandanyc"))
                return notify_fail("��û�з���ҩ�ģ��ϳ�ʲô������\n");
        	if( me->is_busy() )
		return notify_fail("������æ��!\n");
		         
        if ( (int)me->query("jing")<50)
                return notify_fail("��ľ������㣬�޷��ϳɡ�\n");

        if ( (int)me->query("qi")<50)
                return notify_fail("����岻�㣬�޷��ϳɡ�\n");

        if ( (int)me->query("neili")<100)
                return notify_fail("����������㣬�޷��ϳɡ�\n");
        message_vision(HIY"$N���㾫�� �������£������¯��ʼ������\n"NOR,me); 

        message_vision(HIY"$N�������£������¯��ʼ�ϳɵ�ҩ��\n"NOR,me); 
        destruct(ob);
        me->add("jing",-30);
        me->add("qi",-30);
        me->add("neili",-50);
        me->start_busy(9); 
       	call_out("liandan3",6,me);
        return 1;


}




int liandan3(object me)
{
        object ob;
string file;
string *roomlines;
string location;
file = read_file("/clone/medicine/yc2ok");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
           message_vision(HIY"$N�Բ��Ų�æ�Ľ�����ע��¯��,��ʼ�ϳɵ�ҩ��\n"NOR,me); 
           message_vision(HIY"��һ���ҩ¯�еĵ�ҩ�Ѿ����Ρ�\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan2[random(2)]);
           ob = new(location);
           //message_vision(HIY"$N"+(int)me->query_temp("liandanyc")+","+(int)ob->query("lev")+"��\n"NOR,me); 

if ((int)me->query_temp("liandanyc") >= (int)ob->query("lev"))
{
           ob->move(me);
           ob->set("yaocao",1);
           message_vision(HIY"$N�ϳɵõ���"+ob->query("name")+"��\n"NOR,me); 
me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
}
else
{
message_vision(HIR"$N�����ҩ�Ĺ��٣��ϳ�ʧ����!\n"NOR,me); 
destruct(ob);
}           	

if ((int)me->query_skill("poison",1) >= 80 || (int)me->query_skill("duji",1) >= 80)
{
if (random(6)==0) 
{
file = read_file("/clone/medicine/yc2du");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];	
           ob = new(location);
if ((int)me->query_temp("liandanyc") >= (int)ob->query("lev"))
{
           ob->move(me);
           ob->set("yaocao",1);
           message_vision(HIY"$Nʹ�ö����ϳɵõ���"+ob->query("name")+"��\n"NOR,me); 
me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
}
else
{
message_vision(HIR"$N�����ҩ�Ĺ��٣��ϳ�ʧ����!\n"NOR,me); 
destruct(ob);
}           	



}
}

           me->set_temp("liandanyc",0);
           me->delete_temp("liandanyc");
           
           return 1;
} 
