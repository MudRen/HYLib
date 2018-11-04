inherit NPC;

string query_save_file() { return DATA_DIR +"npc/Ҷ��ʿ";}
int ask_heal();
void create()
{
	set_name("Ҷ��ʿ", ({ "ye", "ye", "ye" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λҶ��ʿ��Ц�����æ����\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

set("long","Ҷ��ʿ���ֻش�,���β�������������(ask ye tianshi about heal).\n");
set("inquiry",([
"heal":(:ask_heal:),
]));
	set("area_name","��������ҽ��");
	set("area_file","/d/jindezheng/doctor-room.c");
	setup();
//	carry_object("/obj/std/armor/yinjia")->wear();
	carry_object("/clone/misc/cloth")->wear();
}
int ask_heal()
{
 string *gifts=({"qi","jing","jingli"}),
        *strs=({"��������","��Ѫ����","�����ļ�"}),
        str;
 object ob;
 int i,num=0,max=0,count=0;
 ob=this_player();str="";
if (!living(ob)||environment(ob)!=environment()) return 0;
          for (i=0;i<sizeof(gifts);i++)   {
       max=(int)ob->query("max_"+gifts[i]);
       num=(int)ob->query("eff_"+gifts[i]);
              if (max-num>0)   { 
                    str+="     "+strs[i]+"\n";
                    ob->set_temp("doctor/"+gifts[i],max-num);
       }
          count+=max-num;
         }
          if (count==0) {
  command("say ��û��ʲôë��,��ȥ��Ϣһ�¾ͺ�.\n");
  return 1;
  }
count/=10;
if(count<=0)	count=1;
command("say ��Ĳ�������:\n"+str+"��ȫ�κ���Ҫ"+count+"������.\n");
ob->set_temp("doctor/checked",count);
 return 1;

}
int accept_object(object who,object ob)
{
  int val,wound,i;
  string *gift=({"qi","jing","jingli"}),
         *port=({"ӿȪѨ","������","�ٻ�Ѩ","ӭ��Ѩ","�Ϲ�Ѩ","�羮Ѩ"});
  if (!ob->query("money_id")) return 0;
  if (!who->query_temp("doctor/checked")) return 0;
  val=(int)ob->value()/10;
  if ((int)ob->value()<100)  
       return notify_fail("���ǮҪ����Ĳ����󲻹���!\n");
 message_vision("$N�ý�����$n��"+port[random(sizeof(port))]+"������ȥ,
  $n���������һ�ڳ���,�������ɶ���.\n",this_object(),who);

 for (i=0;i<sizeof(gift);i++)   {
        wound=(int)who->query_temp("doctor/"+gift[i]);
    if (wound>val)   {
          who->add("eff_"+gift[i],val);
          who->delete_temp("doctor");
          return 1;                 }
       who->add("eff_"+gift[i],wound);
       val-=wound;
     }
 who->delete_temp("doctor");
  return 1;
}

